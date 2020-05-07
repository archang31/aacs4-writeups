function get_cookie(name) {
    var normalized = "; " + document.cookie;
    var parts = normalized.split("; " + name + "=\"");
    if (parts.length == 2) {
        return parts[1].split("\"")[0];
    }
    return "";
}

function check_flag() {
    var flag = document.forms["flagChecker"]["flag"].value;
    var submit_button = document.forms["flagChecker"]["submit"];
    var status_field = document.getElementById("status");
    var secret_flag = get_cookie("most_out_of_site_flag");
    if (flag == secret_flag) {
        submit_button.disabled=false;
        status_field.innerHTML = "";
    } else {
        submit_button.disabled=true;
        status_field.innerHTML = "error: does not match flag";
    }
}