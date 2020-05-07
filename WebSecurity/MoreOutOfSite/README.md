# More Out of Site

## Web Security -- 10 points

### Description

Well that was embarrassing... Who knew there was more to a web site then what the browser showed? Not to worry, we're back with a new and improved Javascript version! http://challenge.acictf.com:63225

### Hints

* The Javascript code in an onInput gets called anytime you interact with a text field.
* Is there anyway to view the Javascript definition of this function? It should just be text and your browser has it somewhere (it is running it after all).


### Write-up

Instead of validating it within the HTML `<input>`, you see this line when you look at the html source.

```
<input type="text" id="flag" name="flag" placeholder="ACI{...}" onInput="check_flag()" required>
```

So you then need to view the JavaScript source [./flag_checker.js](./flag_checker.js). This line is the check:

```
if (flag == "ACI{client_side_fail_bb3503bf}") {
        submit_button.disabled=false;
        status_field.innerHTML = "";
    } else {
        submit_button.disabled=true;
        status_field.innerHTML = "error: does not match flag";
    }
```

Note: If you have a hard time seeing the source in your browser when you click on flag_check.js, view it as source in your browser with [view-source:http://challenge.acictf.com:24637/flag_checker.js](view-source:http://challenge.acictf.com:24637/flag_checker.js)
