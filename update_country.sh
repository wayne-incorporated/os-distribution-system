#!/bin/bash

#   <  IDEATION  >
#   Retrieve a row (the top row from the table)
#   Get the external IP data
#   Send that to API (http://ip-api.com/json/ $IP) and get the returned JSON data
#   Extract country code data from returned JSON
#   Store the data to country column 
#   Then call the next row and execute the steps above.

# However, above method might not work because I have to call the api.
# If I can call the api within mysql, then I would have done as I have mentioned above, 
# but it seems that mysql cannot call an web-api.
# Thus, I will execute as the above method but with a little bit of modification.
# Modifications : 
# 	-> I will keep the code which retrieve the whole external IP column for 
# 	   sending the data to api and referencing data in the table.
#	-> As the API returns the data, the data will be entered into the database table 
#	   by locating a row with conditions below: 
#			1. A row that contains referenced external IP
#           	=> It is possible that there could be more than one row that gets selected. 
#                  Thus, number of row may need to be checked before entering data.
#			 

# MySQL account & password
id='root'
pwd='root'

# This will work as a pointer to the table with idex number = var
var=1

# This takes 1 or 2 as an input 
echo Enter 1 to edit PRODUCTFREE table OR Enter 2 to edit PRODUCTPAID table.
read userValue


tableName=""

if [ "$userValue"=="1" ]
then 
	tableName="PRODUCTFREE"

elif [ "$userValue"=="2" ]
then
	tableName="PRODUCTPAID"

else
	echo You have entered wrong option. Please try again.
fi

echo You have chosen the table below :
echo $tableName

# save the result of query in the variable
ip_records=$(sudo mysql -u"$id" -p"$pwd" -DwayneOS -e"SELECT externalIP FROM $tableName")

# This determines the number of loops for reading the data. 
row_count=$(sudo mysql -u"$id" -p"$pwd" -DwayneOS -e"SELECT COUNT(*) FROM $tableName")
row_count=`echo $row_count | cut -d' ' -f2`
echo $row_count

# The data that is read in starts with the label "externalIP". 
# This is to get rid of the label.
ip=`echo $ip_records | cut -d' ' -f1`
ip_records=`echo ${ip_records:\`expr ${#ip} + 1\`}`

# This is to check whether the ip is trimmed correctly.
# if [[ $ip == 'externalIP' ]];
# then 
# 	echo "true"
# else
# 	echo "false"
# fi

# Checking the rest of the ip_records
# echo "WITHOUT External IP Title"
# echo $ip_records

# split the string for checking each ip address
while [ $row_count -ne 0 ]
do
	# retrieve the data with table index idx trim the data
	ip_in_db=$(sudo mysql -u"$id" -p"$pwd" -DwayneOS -e"SELECT externalIP FROM $tableName WHERE idx=$var")
	ip_in_db=`echo $ip_in_db | cut -d' ' -f2`
	echo $ip_in_db	
	
	# Check whether the data has the external ip or not 
	# 'If' the data from the table has external ip address
	# 'then' then compare that ip address and get the country code using api
	if [[ $ip_in_db != 'externalIP' ]] && [[ $ip_in_db != '' ]] && [[ $ip_in_db != NULL ]];
	then		
		
		# echo "This is before cutting ip string : "
		# echo $ip_records

		# echo "This is an array LENGTH before cutting ip string : "
		# echo "${#ip_records[@]}"

		# get 1 ip address from the string data
		ip=`echo $ip_records | cut -d' ' -f1`

		# erase a checked ip address from the string data
		ip_records=`echo ${ip_records:\`expr ${#ip} + 1\`}`

		# echo "This is after cutting ip string : "
		# echo $ip_records

		# echo "This is an array LENGTH AFTER cutting ip string : "
		# echo "${#ip_records[@]}"

		printf -v request "http://ip-api.com/json/%s" "$ip"
		
		echo $request
		
		response=$(sudo curl "$request")

		echo $response
		
		# export only country data from json data
		# FYI jq requires installation
		# Here is the reference :
		# https://stedolan.github.io/jq/download/

		country=`echo $response | jq '.countryCode'`
		
		echo $country
		
		# ---------------------------------------------------#
		#	Previous code was built to count				 #
		#	the number of countries	by the ip address.		 #
		#													 #
		#	Now the country code has to be entered into 	 #
		#	the country column in the selected table.		 #
		# ---------------------------------------------------#

		sudo mysql -u"$id" -p"$pwd" -DwayneOS -e"UPDATE $tableName SET country=$country WHERE externalIP=$ip AND idx=$var"
		
	fi
	var=$((var+1))
	row_count=$((row_count-1))
done


##### NOTE ######################
# This code is still incomplete.#
#################################
