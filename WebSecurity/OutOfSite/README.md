# Out of Site

## Web Security -- 5 points

### Description

The flag submission system lets us see the strings you submitted even when they're wrong. Since some of you may consider that a privacy issue, we decided to demo a flag validation system that checks it client-side before sending the flag to us for checking. Why don't you give it a try: http://challenge.acictf.com:63225

### Hints

* How does your browser know what the right key is to do the check?
* If only there were a way to control+U're view of what the server sent you.


### Write-up

This problem validates a pattern in the input field of the html. Just go and view the source:

```
<!DOCTYPE html>
<html lang="en">

<head>

  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <meta name="description" content="">
  <meta name="author" content="">

  <title>Out of Site</title>
</head>

<body>
  <h1>Out of Site</h1>
  <h2>Flag Validation</h2>
  <p>Look we gave you an easy way to check the flag before you officially submit it!  Best of all, it checks it <i>twice</i>:  once on your end and once on our end.</p>
  <!-- Page Content -->
  <div>
    <form action="check" method="post">
      <label for="flag"><b>Flag:</b></label>
      <input type="text" id="flag" name="flag" placeholder="ACI{...}" pattern="ACI{hidden_in_plain_site_536af5dc}" required>
      <input type="submit">
    </form>
  </div>

</body>

</html>
```
