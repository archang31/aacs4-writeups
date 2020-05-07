# Most Out of Site

## Web Security -- 20 points

### Description

Alright, one more try. We had to think long and hard about how to keep you from viewing the flag. After a quick snack break, we had an epiphany. Your tricks won't work this time. http://challenge.acictf.com:35515/

### Hints

* What on earth could [snack food](https://en.wikipedia.org/wiki/HTTP_cookie) have to do with this problem?
* The browser must be storing these cookies somewhere...
* If you're getting tired of using a browser, the Python [Requests](https://requests.readthedocs.io/en/master/) library is pretty useful for interacting with web servers.


### Write-up

Same as before, but the string that it is checked against is not directly in the JavaScript. Looking at [./flag_checker.js](./flag_checker.js), you can see it gets the flag with this line: `var secret_flag = get_cookie("most_out_of_site_flag");`. It is checking against your cookie so let's go check out our network traffic (developer tools->network). Look at the response header when you visit http://challenge.acictf.com:35515/, you see:

```
HTTP/1.1 200 OK
Content-Type: text/html; charset=utf-8
Content-Length: 984
Set-Cookie: most_out_of_site_flag="ACI{cookies_fail_too_60f43d39}"; Expires=Wed, 06-May-2020 23:36:17 GMT; Max-Age=300; Path=/; SameSite=Strict
```

You can also just run the code from [./flag_checker.js](./flag_checker.js) in your console:

```
> get_cookie("most_out_of_site_flag")
"ACI{cookies_fail_too_60f43d39}"
```
