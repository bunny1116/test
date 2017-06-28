@model List<WF.ERMT.Application.Entities.CustomEntities.PepRequestAutoAssignmentEntity> 
@{
    ViewBag.Title = "CPTMembersTeamAssignments";
    Layout = "~/Views/Shared/layout.cshtml";

}
@*<link rel="stylesheet" href="//code.jquery.com/ui/1.12.0/themes/base/jquery-ui.css" />
<link rel="stylesheet" href="/resources/demos/style.css" />
<script src="https://code.jquery.com/jquery-1.12.4.js"></script>
<script src="https://code.jquery.com/ui/1.12.0/jquery-ui.js"></script>

　
<link href="~/AdminLTE/plugins/font-awesome/css/font-awesome.min.css" rel="stylesheet" />
<link href="~/AdminLTE/plugins/ionicons/css/ionicons.css" rel="stylesheet" />
<link href="~/AdminLTE/bootstrap/css/bootstrap.min.css" rel="stylesheet" />
<link href="~/AdminLTE/dist/css/admin-lte.min.css" rel="stylesheet" />
<link href="~/AdminLTE/dist/css/skins/_all-skins.min.css" rel="stylesheet" />
<link href="~/AdminLTE/bootstrap/css/bootstrap.min.css" rel="stylesheet" />

<script src="~/AdminLTE/plugins/datatables/js/jquery.dataTables.min.js"></script>
<script src="~/AdminLTE/plugins/datatables/js/dataTables.bootstrap.min.js"></script>*@

@using (Html.BeginForm("UpdateCPTMembersTeamAssignments", "PEPDetails", FormMethod.Post, new { @id = "formPost" }))
{
  
        <div class="row">
            <div style="float:left;">
                @Html.Partial("PEPLeftMenu")
            </div>
            <div class="col-lg-9 col-md-9">
                <div class="ms-core-pageTitle">
                    <div class="col-lg-8">
                       Team Assignments
                    </div>
                   
                </div><br />
                <div class="box-body " style="font-family:Verdana;font-size:smaller">
                    @*<input type="hidden" id="selectedCR" value='@data.ToString()'/>*@
                    @if (!ViewBag.isSuccess)
                    {
                        <span style="color:red">
                            @Html.ValidationMessage("Error", new { style = "font-size:16px" })
                        </span>

                    }
                    else
                    {
                        <span style = "color:green" >
                            @Html.ValidationMessage("Success", new { style = "font-size:16px" })
                            </span>

                    }
                </div>
                <br />
               <div class="row">
   
        <div class="col-sm-3"> Total Team Assignment Threshold Enabled</div>
                   <div class="col-sm-1">
                       @for (int i = 0; i < Model.Count; i++)
                       {

                           @Html.DropDownListFor(modelItem => modelItem[i].TotalTeamAutoAssignmentEnabled, new List<SelectListItem>()
                               { new SelectListItem { Text = "No", Value = "false", Selected = (bool)Model[i].TotalTeamAutoAssignmentEnabled },
                                   new SelectListItem { Text = "Yes", Value = "true", Selected = (bool)Model[i].TotalTeamAutoAssignmentEnabled }, },
                            new { @class = "form-control", id = "TotalTeamAutoAssignmentEnabled", @onchange = "javascript:TotalTeamAssignment(this);" })

                           break;
                       }
                       </div>

                   </div>
    <br /><br />
                <table id="example" class="table table-bordered table-hover table-striped">
                    <thead style="font-weight:bold; background-color:#337ab7;color:white; font-family:Verdana, Geneva, Tahoma, sans-serif">
                        <tr>
                            <th class="sorting_asc">Sl.no</th>

                            <th class="sorting_asc" tabindex="0" aria-controls="example2" rowspan="1" colspan="1" aria-label="Rendering engine: activate to sort column descending" aria-sort="ascending">Employee</th>
                            <th class="sorting_asc" tabindex="0" aria-controls="example2" rowspan="1" colspan="1" aria-label="Rendering engine: activate to sort column descending" aria-sort="ascending">Role</th>
                            <th class="sorting_asc" tabindex="0" aria-controls="example2" rowspan="1" colspan="1" aria-label="Rendering engine: activate to sort column descending" aria-sort="ascending">Auto Assignment</th>
                            <th class="sorting_asc" tabindex="0" aria-controls="example2" rowspan="1" colspan="1" aria-label="Rendering engine: activate to sort column descending" aria-sort="ascending">Start Date</th>
                            <th class="sorting_asc" tabindex="0" aria-controls="example2" rowspan="1" colspan="1" aria-label="Rendering engine: activate to sort column descending" aria-sort="ascending">End Date</th>
                            <th class="sorting_asc" tabindex="0" aria-controls="example2" rowspan="1" colspan="1" aria-label="Rendering engine: activate to sort column descending" aria-sort="ascending">Assignment Threshold %</th>
                            <th class="sorting_asc" tabindex="0" aria-controls="example2" rowspan="1" colspan="1" aria-label="Rendering engine: activate to sort column descending" aria-sort="ascending">No Longer Team Member</th>
                        </tr>
                    </thead>

                    <tbody>
                        @for (int i = 0; i < Model.Count; i++)
                {
                            <tr>
                                <td>
                                    @(i + 1)
                                    @Html.HiddenFor(modelItem => modelItem[i].AutoAssignmentId)
                                    @*@Model[i].AutoAssignmentId*@
                                </td>
                                <td>
                                    <a href="#" id='@Model[i].AutoAssignmentId' title="Go to Team Reassignment" style="color:Blue !important" onclick='GotoTeamReassignment(this);'>
                                        @Model[i].Employee
                                    </a>
                                    @Html.HiddenFor(modelItem => modelItem[i].Employee)
                                    @Html.HiddenFor(modelItem => modelItem[i].UserId, new { id = string.Concat("userid", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0) })
                                    @Html.HiddenFor(modelItem => modelItem[i].LastAutoAssignmentDate)
                                    @*@Model[i].Employee*@
                                </td>
                                <td>
                                    @Html.TextBoxFor(modelItem => modelItem[i].RoleName, new { style = "width:16em;pointer-events: none;border-style:none;background-color:transparent" })
                                    @*@Model[i].RoleName*@
                                </td>
                                <td>
                                    @Html.DropDownListFor(modelItem => modelItem[i].IsAutoAssignmentEnabled, new List<SelectListItem>()
                               { new SelectListItem { Text = "No", Value = "false", Selected = (bool)Model[i].IsAutoAssignmentEnabled },
                                   new SelectListItem { Text = "Yes", Value = "true", Selected = (bool)Model[i].IsAutoAssignmentEnabled }, },
                                   new { @class = "form-control", id = string.Concat("IsAutoAssignmentEnabled_", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0), @onchange = "javascript:CheckThresholdPercentage(this);" })
                                    <input type="hidden" style="font-family:Verdana" class="btn btn-primary" value=" " id=@string.Concat("isautosssignmentenabledsave", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0) />

                                    @*<select name="IsAutoAssignmentEnabled" class="form-control" id="@string.Concat("IsAutoAssignmentEnabled", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0)">

                                            <option value="@Model[i].IsAutoAssignmentEnabled.Value" @if ((Model[i].IsAutoAssignmentEnabled.Value == true)) { @Html.Raw("selected")          }>
                                                Y
                                            </option>
                                            <option value="@Model[i].IsAutoAssignmentEnabled.Value" @if (@Model[i].IsAutoAssignmentEnabled.Value == false) { @Html.Raw("selected")           }>
                                                N
                                            </option>

                                        </select>*@

                                </td>
                                <td contenteditable>

                                    @Html.TextBoxFor(modelItem => modelItem[i].AutoAssignmentBlackOutStartDate, new { @class = "form-control input-normal input-sm", id = string.Concat("startdate", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0) })
                                    <input type="hidden" style="font-family:Verdana" class="btn btn-primary" value=" " id=@string.Concat("startdatesave", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0) />

                                    @*<div class="col-sm-3"><input type="text" class="form-control input-normal input-sm" id="@string.Concat("startdate", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0)" name="AutoAssignmentBlackOutStartDate" value='@Model[i].AutoAssignmentBlackOutStartDate' /></div>*@
                                </td>
                                <td ccontenteditable>

                                    @Html.TextBoxFor(modelItem => modelItem[i].AutoAssignmentBlackOutEndDate, new { @class = "form-control input-normal input-sm", id = string.Concat("enddate", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0) })
                                    <input type="hidden" style="font-family:Verdana" class="btn btn-primary" value=" " id=@string.Concat("enddatesave", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0) />

                                    @*<div class="col-sm-3"><input type="text" class="form-control input-normal input-sm" id="@string.Concat("enddate", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0)" name="AutoAssignmentBlackOutEndDate" value='@Model[i].AutoAssignmentBlackOutEndDate' /></div>*@
                                </td>
                                <td contenteditable>
                                    @Html.TextBoxFor(modelItem => modelItem[i].AssignmentThresholdPercentage, new { @class = "form-control input-normal input-sm", id = string.Concat("thresholdpercentage", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0) })
                                    @*<div class="col-sm-3"><input type="text" class="form-control input-normal input-sm" id="@string.Concat("thresholdpercentage", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0)" name="AssignmentThresholdPercentage" value='@Model[i].AssignmentThresholdPercentage' /></div>*@
                                    <input type="hidden" style="font-family:Verdana" class="btn btn-primary" value="0" id=@string.Concat("thresholdsave", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0) />
                                </td>

                                <td contenteditable>
                                    @Html.CheckBoxFor(modelItem => modelItem[i].NolongerTeamMember, new { @class = "form-control input-normal input-sm", id = string.Concat("nolongerteammember|", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0), @onchange = "javascript:CheckThresholdPercentageNoLonger(this);", autocomplete = "off" })
                                    @*<input type="checkbox" style="font-family:Verdana" name="NolongerTeamMember" value="true" onchange='javascript:CheckThresholdPercentageNoLonger(this);'id=@string.Concat("nolongerteammember", (@Model[i] != null) ? @Model[i].AutoAssignmentId : 0)  />*@
                                </td>

                            </tr>
                        }
                    </tbody>
                </table>
            </div>

                <div class="container">
                    <div class="row">
                        <div class="col-lg-12">
                            <div class="col-lg-14" style="text-align:right">
                                
                                <input type="button" style="font-family:Verdana" class="btn btn-primary" value="Submit" id="saveForm" onclick="displayAllDataTable()"/>
                                <input type="button" style="font-family:Verdana;color:red" class="btn btn-primary" name="BtnSubmit" value="Cancel" id="btncancel" />

                            </div>
                        </div>
                    </div>
                </div>

            </div>
}

　
<script>

    $(document).ready(function () {
        
        var totalteamassignmentenabled= $('#TotalTeamAutoAssignmentEnabled').val();
        if(totalteamassignmentenabled=="false")
        {
            
           

            var model = @Html.Raw(Json.Encode(Model));
            $.each(model, function(i, item) {
                $('#startdate'+ item.AutoAssignmentId).datepicker();
                $('#enddate' + item.AutoAssignmentId).datepicker();
                $('#startdatesave'+item.AutoAssignmentId).val($('#startdate'+item.AutoAssignmentId).val());
                $('#enddatesave'+item.AutoAssignmentId).val($('#enddate'+item.AutoAssignmentId).val());
                $('#thresholdsave'+item.AutoAssignmentId).val($('#thresholdpercentage'+item.AutoAssignmentId).val());
                $('#isautosssignmentenabledsave'+item.AutoAssignmentId).val($('#IsAutoAssignmentEnabled_'+item.AutoAssignmentId).val());

　
                //$('#'+item.AutoAssignmentId).attr("disabled", "disabled");
               // $('#startdate'+item.AutoAssignmentId).attr("disabled", "disabled");
               // $('#enddate'+ item.AutoAssignmentId).attr("disabled", "disabled");
                $('#thresholdpercentage'+ item.AutoAssignmentId).attr("disabled", "disabled");
                //$('#IsAutoAssignmentEnabled_'+ item.AutoAssignmentId).attr("disabled", "disabled");

                //$('#startdate'+item.AutoAssignmentId).val(" ");
                //$('#enddate'+ item.AutoAssignmentId).val(" ");
                $('#thresholdpercentage'+ item.AutoAssignmentId).val("0");
                //$('#IsAutoAssignmentEnabled_'+ item.AutoAssignmentId).val("false");
                if(item.IsAutoAssignmentEnabled==true)
                {
                    $('#startdate'+item.AutoAssignmentId).attr("disabled", "disabled");
                    $('#enddate'+ item.AutoAssignmentId).attr("disabled", "disabled");

                }

　
            });
            $('#example').DataTable({
                "searching": false,
                "aLengthMenu": [ 10, 25, 50, 100, 1000 ]
            });

        }
        else
        {
            $('#example').DataTable({
                "searching": false,
                "aLengthMenu": [ 10, 25, 50, 100, 1000 ]
            });
            var model = @Html.Raw(Json.Encode(Model));
            $.each(model, function(i, item) {

　
                $('#startdate'+ item.AutoAssignmentId).datepicker();
                $('#enddate' + item.AutoAssignmentId).datepicker();

                if(item.IsAutoAssignmentEnabled==true)
                {
                    $('#startdate'+item.AutoAssignmentId).attr("disabled", "disabled");
                    $('#enddate'+ item.AutoAssignmentId).attr("disabled", "disabled");

                }

            });
            //$(model).each(function (m) {
            //    debugger;
            //    $('#startdate'+ m.AutoAssignmentId).datepicker();
            //    $('#enddate' + m.AutoAssignmentId).datepicker();
            //})
            //$('#startdate').datepicker();
            // $('#enddate').datepicker();

        }
        });

    function displayAllDataTable() {
    $("#example_length select").val(1000);
    $("#example_length select").trigger("change");

    $("#formPost").submit();

    }
    function TotalTeamAssignment(value)
    {
        
        //var assignmentid =value.id;

        var val= value.value;

        if(val=="false")
        {
            var model = @Html.Raw(Json.Encode(Model));
            $.each(model, function(i, item) {

                $('#startdatesave'+item.AutoAssignmentId).val($('#startdate'+item.AutoAssignmentId).val());
                $('#enddatesave'+item.AutoAssignmentId).val($('#enddate'+item.AutoAssignmentId).val());
                $('#thresholdsave'+item.AutoAssignmentId).val($('#thresholdpercentage'+item.AutoAssignmentId).val());
                $('#isautosssignmentenabledsave'+item.AutoAssignmentId).val($('#IsAutoAssignmentEnabled_'+item.AutoAssignmentId).val());

　
                $('#'+item.AutoAssignmentId).attr("disabled", "disabled");
                //$('#startdate'+item.AutoAssignmentId).attr("disabled", "disabled");
                //$('#enddate'+ item.AutoAssignmentId).attr("disabled", "disabled");
                $('#thresholdpercentage'+ item.AutoAssignmentId).attr("disabled", "disabled");
                //$('#IsAutoAssignmentEnabled_'+ item.AutoAssignmentId).attr("disabled", "disabled");

                //$('#startdate'+item.AutoAssignmentId).val(" ");
                //$('#enddate'+ item.AutoAssignmentId).val(" ");
                $('#thresholdpercentage'+ item.AutoAssignmentId).val("0");
                //$('#IsAutoAssignmentEnabled_'+ item.AutoAssignmentId).val("false");

　
            });

        }
        else{
            var model = @Html.Raw(Json.Encode(Model));
            $.each(model, function(i, item) {

　
                $('#startdate'+item.AutoAssignmentId).removeAttr("disabled");
                $('#enddate'+item.AutoAssignmentId).removeAttr("disabled");
                $('#enddate'+ item.AutoAssignmentId).removeAttr("disabled");
                $('#thresholdpercentage'+ item.AutoAssignmentId).removeAttr("disabled");
                $('#IsAutoAssignmentEnabled_'+ item.AutoAssignmentId).removeAttr("disabled");

                $('#startdate'+item.AutoAssignmentId).val($('#startdatesave'+item.AutoAssignmentId).val());
                $('#enddate'+ item.AutoAssignmentId).val($('#enddatesave'+item.AutoAssignmentId).val());
                $('#thresholdpercentage'+ item.AutoAssignmentId).val($('#thresholdsave'+item.AutoAssignmentId).val());
                $('#IsAutoAssignmentEnabled_'+ item.AutoAssignmentId).val($('#isautosssignmentenabledsave'+item.AutoAssignmentId).val());
                if(item.IsAutoAssignmentEnabled==true)
                {
                    $('#startdate'+item.AutoAssignmentId).attr("disabled", "disabled");
                    $('#enddate'+ item.AutoAssignmentId).attr("disabled", "disabled");

                }

　
　
            });
        }

    }

    function GotoTeamReassignment(value){

        var assignmentid =value.id;
        var userid = $('#userid'+assignmentid).val();

        var url= window.rootUrl + "PEPDetails/TeamRequestAssignmentOverride?UserID="+userid;
        window.location.href = url;

　
    }

    function CheckThresholdPercentageNoLonger(value)
    {

        var assignmentid =value.id;

        var val= value.checked;
        var id = assignmentid.split('_');

        if(val)
        {
            if($('#thresholdpercentage'+id[1]).val()!="0")
            {
                $('#thresholdsave'+id[1]).val($('#thresholdpercentage'+id[1]).val());
                $('#thresholdpercentage'+id[1]).val("0");
            }
        }
        else if($('#thresholdpercentage'+id[1]).val()=="0")
        {
            $('#thresholdpercentage'+id[1]).val($('#thresholdsave'+id[1]).val());
        }

    }

    function CheckThresholdPercentage(value) {
        var totalteamassignment= $('#TotalTeamAutoAssignmentEnabled').val();
        var assignmentid =value.id;

        var val= value.value;

        var id = assignmentid.split('_');
        //var valthresholdvalue = $('#thresholdpercentage'+id[1]).val();
        if(val=="false")
        {
            if($('#thresholdpercentage'+id[1]).val()!="0")
            {
                $('#thresholdsave'+id[1]).val($('#thresholdpercentage'+id[1]).val());
                $('#thresholdpercentage'+id[1]).val("0");
            }
        }
        else if($('#thresholdpercentage'+id[1]).val()=="0")
        {
            if(totalteamassignment != "false")
            {
                $('#thresholdpercentage'+id[1]).val($('#thresholdsave'+id[1]).val());
            }
        }

        if(val=="false")
        {
            $('#startdate'+ id[1]).removeAttr("disabled");
            $('#enddate'+ id[1]).removeAttr("disabled");

　
            $('#startdate'+ id[1]).val($('#startdatesave'+id[1]).val());
            $('#enddate'+ id[1]).val($('#enddatesave'+id[1]).val());

        }else
        {
            $('#startdatesave'+id[1]).val($('#startdate'+id[1]).val());
            $('#enddatesave'+id[1]).val($('#enddate'+id[1]).val());
            $('#startdate'+ id[1]).attr("disabled", "disabled");
            $('#enddate'+ id[1]).attr("disabled", "disabled");
            $('#startdate'+ id[1]).val(" ");
            $('#enddate'+ id[1]).val(" ");
            //$('#startdate'+id[1]).val($('#startdatesave'+id[1]).val());
            //$('#enddate'+id[1]).val($('#enddatesave'+id[1]).val());
        }

　
　
    }
    function updateAssignment(r, id)
    {
       // debugger;

        var PepRequestAutoAssignmentEntity = {
            AutoAssignmentId: AutoAssignmentId,
            UserId: $('#userid' + id).val(),
            Employee: $('#Employee' + id).val(),
            RoleName: $('#rolename' + id).val(),
            IsAutoAssignmentEnabled: $('#IsAutoAssignmentEnabled' + id).val(),
            AutoAssignmentBlackOutStartDate: $('#startdate' + id).val(),
            AutoAssignmentBlackOutEndDate: $('#enddate' + id).val(),
            AssignmentThresholdPercentage: $('#AssignmentThresholdPercentage' + id).val(),
        };

        $.ajax({
            url: '/UserMaintenance/UpdateCPTMembersTeamAssignments/',
            data: JSON.stringify({ PepRequestAutoAssignmentEntity: PepRequestAutoAssignmentEntity }),
            type: 'POST',
            contentType: "application/json; charset=utf-8",
            success: function (data) {
                $('#btnClose').trigger("click");
                $('#userDetails').html(data);
            },
            error: function (data) {
                $('#msg').html("data");
            }
        });
    }

    $("#btncancel").on("click", function (ev) {
        ev.preventDefault();
        window.location.href = window.rootUrl + "PEPDetails/PDTManagerDashboardPage";

    });

</script>
