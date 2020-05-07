function check_flag() {
    var flag = document.forms["flagChecker"]["flag"].value;
    var submit_button = document.forms["flagChecker"]["submit"];
    var status_field = document.getElementById("status");
    if (flag == "ACI{client_side_fail_bb3503bf}") {
        submit_button.disabled=false;
        status_field.innerHTML = "";
    } else {
        submit_button.disabled=true;
        status_field.innerHTML = "error: does not match flag";
    }
}