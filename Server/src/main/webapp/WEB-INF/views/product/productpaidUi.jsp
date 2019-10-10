<%@ page language="java" contentType="text/html; charset=EUC-KR" pageEncoding="EUC-KR"%> 
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<link rel="stylesheet" type="text/css" media="screen" href="/resources/jquery/jquery-ui.min.css" />
<link rel="stylesheet" type="text/css" media="screen" href="/resources/jquery/ui.jqgrid.css" />
<link rel="stylesheet" type="text/css" media="screen" href="/resources/css/style.css" />
<link rel="stylesheet" type="text/css" media="screen" href="/resources/css/button.css" />

<script src="/resources/jquery/jquery-1.11.2.min.js" type="text/javascript"></script> 
<script src="/resources/jquery/jquery-migrate-1.2.1.js" type="text/javascript"></script> 
<script src="/resources/jquery/grid.locale-en.js" type="text/javascript"></script>
<script src="/resources/jquery/jquery.jqGrid.src.js" type="text/javascript"></script>
<script src="/resources/jquery/JQuery-lib.js" type="text/javascript"></script>

<script type="text/javascript">

$(document).ready(function(){
       
   $("#list").jqGrid({
	  url			: "/Product/InqProductPaid.do",
      loadtext		: 'Loading..',
      datatype		: "json",
	  mtype			: "post",
	  width			: "900",
	  height		: "700", 
	  jsonReader 	: { repeatitems: false },
      colNames		: ['idx','vendorID','productID','serialNumber','deviceType',
              		   'deviceVolume','imgName','userIPAddress','lastReleaseDate',
              		   'releaseCount','customerInfo0','customerInfo1','flag'], //칼럼 이름
      colModel		: [ //데이터 매핑 및 로우 속성
            {name:'idx', width:"4%"},
		  	{name:'vendorID',		width:"8%"},
          	{name:'productID' ,		width:"8%"},
          	{name:'serialNumber',	width:"8%"},
          	{name:'deviceType',		width:"8%"},
          	{name:'deviceVolume',	width:"8%"},
          	{name:'imgName', 		width:"8%"},
          	{name:'userIPAddress',	width:"8%"},
          	{name:'lastReleaseDate',width:"8%" ,formatoptions: { srcformat: "ISO8601Long", newformat: "m/d/Y h:i A" }},
          	{name:'releaseCount',	width:"8%"},
          	{name:'customerInfo0',	width:"8%"},
          	{name:'customerInfo1',	width:"8%"},
          	{name:'flag', hidden:true},
          	],
	  
	  rowList		: [10,20,30],
      caption 		: "Paid User Records",
      pager			: '#pager',
      rowNum		: '10',
      viewrecords	: true,
      
      emptyrecords	: "No data",
      loadonce		: false,
      pager			: $("#pager"),
      contentType: "application/json; charset=utf-8",
      
      serializeGridData    : function (postData) {
          postData.formData = $("#list").serializeArray();
          return JSON.stringify(postData);
      },
       ajaxGridOptions  : {
    	   contentType :"application/json;charset=UTF-8"},  //한글 안깨지게
     
     
   ondblClickRow : function(idx) {

		var rowdata = $("#list").jqGrid('getRowData', idx);
		
		jQuery("#idx").val(rowdata.idx);
		jQuery("#vendorID").val(rowdata.vendorID);
		jQuery("#productID").val(rowdata.productID);
		jQuery("#serialNumber").val(rowdata.serialNumber);
		jQuery("#deviceType").val(rowdata.deviceType);
		jQuery("#deviceVolume").val(rowdata.deviceVolume);
		jQuery("#userIPAddress").val(rowdata.userIPAddress);
		jQuery("#lastReleaseDate").val(rowdata.lastReleaseDate);
		jQuery("#releaseCount").val(rowdata.releaseCount);
		jQuery("#customerInfo0").val(rowdata.customerInfo0);
		jQuery("#customerInfo1").val(rowdata.customerInfo1);
		jQuery("#imgName").val(rowdata.imgName);
	}
});
 //combobox change
	jQuery.ajax({
	type : "POST",
	url : "/devicevolume/volumeAll.do",
	dataType : "JSON", // 옵션이므로 JSON으로 받을게 아니면 안써도 됨
	contentType : "application/json;charset=UTF-8", //한글 안깨지게
	success : function(data) {
		$.each(data, function(){
			$('.wrap-loading').addClass('display-none');
			var volsize = this.volumeSize;
			$("#deviceVolume").append("<option value='"+volsize+"'>"+volsize+"</option");
		});
	},beforeSend:function(){
        //$('.wrap-loading').addClass('display-none');
		$('.wrap-loading').removeClass('display-none');
		
    },
	error : function(xhr, status, error) {

		alert(xhr.reponseText);
	}

});


jQuery("#list").jqGrid('navGrid', "#pager", {
					edit : false,
					add : false,
					del : false,
					search : false,
					refresh : false
					});
//flag
var InsertArray = new Array();
var count = 0;
var gridNm = "list";
//add button
$("#btnInsert").click(function() {

	//var order = $("#list").getGridParam("records") + 1;
	var idx = jQuery("#idx").val();
	var vendorID = jQuery("#vendorID").val();
	var productID = jQuery("#productID").val();
	var serialNumber = jQuery("#serialNumber").val();
	var deviceType = jQuery("#deviceType").val();
	var deviceVolume = jQuery("#deviceVolume").val();
	var userIPAddress = jQuery("#userIPAddress").val();
	//var lastReleaseDate = jQuery("#lastReleaseDate").val();
	var imgName = jQuery("#imgName").val();
	var releaseCount = jQuery("#releaseCount").val();
	var customerInfo0 = jQuery("#customerInfo0").val();
	var customerInfo1 = jQuery("#customerInfo1").val();		
	var date= new Date();
	var lastReleaseDate = date.getFullYear()+"-"+(date.getMonth()+1)+"-"+date.getDate()+" "+date.getHours()+":"+date.getMinutes()+":"+date.getSeconds();
	
	var addData = {
		//"order" : order,
		"idx" : idx,
		"vendorID" : vendorID,
		"productID" : productID,
		"serialNumber" : serialNumber,
		"deviceType" : deviceType,
		"deviceVolume" : deviceVolume,
		"imgName" : imgName,
		"userIPAddress" : userIPAddress,
		"lastReleaseDate" : lastReleaseDate,
		"releaseCount" : releaseCount,
		"customerInfo0" : customerInfo0,
		"customerInfo1" : customerInfo1,
		"flag" : "I"
	};
	$("#list").jqGrid('addRowData', idx, addData, "last");
	//color change
	BackgroundChange(gridNm, idx, "#8AE634");
	InsertArray[count] = total;
	count++;
});

//select button
$("#btnSelect").click(function() {

	$("#list").trigger('reloadGrid');

});

//Init button
$("#btnInit").click(function() {
	jQuery("#idx").val('');
	jQuery("#vendorID").val('');
	jQuery("#productID").val('');
	jQuery("#serialNumber").val('');
	jQuery("#deviceType").val('');
	jQuery("#deviceVolume").val('');
	jQuery("#imgName").val('');
	jQuery("#userIPAddress").val('');
	jQuery("#lastReleaseDate").val('');
	jQuery("#releaseCount").val('');
	jQuery("#customerInfo0").val('');
	jQuery("#customerInfo1").val('');
	$("#list").resetSelection();
});

//delete button
$("#btnDelete").click(function() {
	var rowid = $("#list").jqGrid('getGridParam', "selrow");
	var idx = $("#list").jqGrid('getRowData', rowid).idx;
	BackgroundChange(gridNm, rowid, "#FF0000");
	
	var setData = {
			"idx" : idx,
			"flag" : "D"
		};

	$("#list").setRowData(rowid, setData,false);
});

//save button
$("#btnSave").click(function() {
	var rowid = $("#list").jqGrid('getGridParam', "selrow");
	//var order = $("#list").jqGrid('getRowData', rowid).order;
	var idx =jQuery("#idx").val();
	var vendorID = jQuery("#vendorID").val();
	var productID = jQuery("#productID").val();
	var serialNumber = jQuery("#serialNumber").val();
	var deviceType = jQuery("#deviceType").val();
	var deviceVolume = jQuery("#deviceVolume").val();
	var imgName = jQuery("#imgName").val();
	var userIPAddress = jQuery("#userIPAddress").val();
	var lastReleaseDate = jQuery("#lastReleaseDate").val();
	var releaseCount = jQuery("#releaseCount").val();
	var customerInfo0 = jQuery("#customerInfo0").val();
	var customerInfo1 = jQuery("#customerInfo1").val();	
	
	var isInsert = false;
	//$("#list").setCell(rowid, 'idx', idx);
	$("#list").setCell(rowid, 'vendorID', vendorID);
	$("#list").setCell(rowid, 'productID', productID);
	$("#list").setCell(rowid, 'serialNumber', serialNumber);
	$("#list").setCell(rowid, 'deviceType', deviceType);
	$("#list").setCell(rowid, 'deviceVolume', deviceVolume);
	$("#list").setCell(rowid, 'imgName', imgName);
	$("#list").setCell(rowid, 'userIPAddress', userIPAddress);
	$("#list").setCell(rowid, 'lastReleaseDate', lastReleaseDate);
	$("#list").setCell(rowid, 'releaseCount', releaseCount);
	$("#list").setCell(rowid, 'customerInfo0', customerInfo0);
	$("#list").setCell(rowid, 'customerInfo1', customerInfo1);
	
	var deleteflag = $("#list").jqGrid('getRowData', rowid).flag;
	var setData = {
			"idx" : idx,
			"flag" : "U"
		};
	if(!(deleteflag == "D")){
	$("#list").setRowData(rowid, setData,false);
	}

	var gridData = jQuery("#list").getRowData();
	jQuery.ajax({

		type : "POST",
		url : "/Productpaid/Save.do",
		// url:"/mainUi.do",
		dataType : "JSON", // 옵션이므로 JSON으로 받을게 아니면 안써도 됨
		data : JSON.stringify(gridData),
		contentType : "application/json;charset=UTF-8", //한글 안깨지게
		success : function(data) {
			$("#list").trigger('reloadGrid');
		},
		error : function(xhr, status, error) {
			alert(xhr.reponseText);
		}

	});
	

});
//iframe 길이
$("#main_Iframe", parent.document).width(1450);

	//center popup position
						function popWin(url, wname, w, h, ptype, t, l) {
							var pWin, tVal, lVal;
							if (t == "c") {
								lVal = (screen.availWidth - w) / 2;
								tVal = (screen.availHeight - h) / 2;
							} else {
								tVal = (t != null) ? t : 0;
								lVal = (l != null) ? l : 0;
							}

							var popOpt = "width=" + w + "px,height=" + h
									+ "px, top=" + tVal + ", left=" + lVal;
							if (ptype == 0)
								popOpt += ",scrollbars=no";

							if (ptype == 1)
								popOpt += ",scrollbars=yes";

							if (ptype == 2)
								popOpt += ",scrollbars=yes,resizable=yes";

							pWin = window.open(url, wname, popOpt);
							//  pWin.focus();

							return pWin;
						}

						$("#btnImgSelect").click(function() {
							popWin('productpaidUiPop.do', 'name', 500, 500, 0, 'c');

						});
						function setImgName(name) {
							jQuery("#imgName").val(name);
						}
						

					});
</script>

</head>
<body>
	<div class="wrap-loading display-none">
    	<div><img src="/resources/images/viewLoading.gif" /></div>
	</div>
	
<div class="list_area">
		<table id="list"></table>
		<div id="pager"></div>
	</div>
	<div class="crud_area">
	<div class="crud_area_box">
				<table class="table_area">
					<tr class="center">
						<td><input type="button" value="Reload" id="btnSelect"
							class="button"></td>
						<td><input type="button" value="Reset" id="btnInit"
							class="button"></td>
						<td><input type="button" value="Add" id="btnInsert"
							class="button add"></td>
						<td><input type="button" value="Delete" style="width:60pt;" id="btnDelete"
							class="button delete"></td>
					</tr>
					<tr>
						<td>idx</td>
						<td><input type="text" id="idx" class="input" readonly="readonly"></td>
						<td>vendorID</td>
						<td><input type="text" id="vendorID" maxlength="64"  class="input"></td>
					</tr>
					<tr>
						<td>productID</td>
						<td><input type="text" id="productID" maxlength="64" class="input"></td>
						<td>deviceType</td>
						<td><select id="deviceType">
							<option value="USB">USB</option>
							<option value="SSD">SSD</option>
					</select></td>
					</tr>
					<tr>
					
						<td>serialNumber</td>
						<td><input type="text" id="serialNumber" maxlength="100" class="input"></td>
					</tr>
					
					<tr>
						<td>deviceVolume</td>
						<td><select id="deviceVolume" /></select></td>
						<td>userIPAddress</td>
						<td><input type="text" id="userIPAddress" maxlength="15" class="input"></td>
					</tr>
					<tr>
						<td>LastReleaseDate</td>
						<td><input type="text" id="lastReleaseDate" maxlength="15" class="input" readonly="readonly"></td>
						<td>ReleaseCount</td>
						<td><input type="text" id="releaseCount" maxlength="15" class="input"></td>
					</tr>
					<tr>
						<td>CustomerInfo 0</td>
						<td><input type="text" id="customerInfo0" maxlength="200" class="input"></td>
						<td>CustomerInfo 1</td>
						<td><input type="text" id="customerInfo1" maxlength="200" class="input"></td>
					</tr>
					<tr>
						<td>imgName</td>
						<td><input type="text" id="imgName"  class="input" readonly="readonly"></td>
						<td><input type="button" id="btnImgSelect" maxlength="100" class="button" value="선택"></td>
						
					</tr>
				</table>
			</div>
			<div class="save_area">
				<input type="button" value="Save" style="width:60pt;" id="btnSave" class="button save">
			</div>
	</div>
</body>
</html>
