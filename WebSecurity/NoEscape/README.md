# No Escape

## Web Security -- 60 points

### Description

Since in-person events are currently banned, some magician we've never heard of is trying to sell us on the idea of a "digital" magic show where the magician logs in using an impossible password. For added assurances, one lucky audience member is able to login and see the hash of the password as proof the password is impossible. We're willing to bet the secret to this magic trick is not all that complicated. http://challenge.acictf.com:43248/

### Hints

* Inexperienced web application developers don't always esacpe/sanitize user inputs in there database query strings. This frequently allows [SQL injection](https://en.wikipedia.org/wiki/SQL_injection) attacks that result in unintended behavior.
* The developer was pretty new, so just causing the query to error out may get you more information for the exploit. What happens when you use a single ' or " in each of the login fields?
* You'll need to login as a specific user. If you're new to SQL syntax, [this](https://www.w3schools.com/sql/sql_where.asp) might be useful resource for understanding the intended query and how you can manipulate it for your purposes.


### Write-up

So you need to log in. Start by just putting `'` as both username and password. You then get this error:

```
Oops! It looks like the following query caused an error...
SELECT username FROM users WHERE username = ''' AND pwHash = '265fda17a34611b1533d8a281ff680dc5791b0ce0a11c25b35e11c8e75685509'
```

So you now know the query. Try the very traditional `admin' OR 1=1; -- ` and you log in, but you do not get the flag. Instead, you get `Welcome admin! The "hash" for account 'houdini' is 'Not a hash'.`. Ok, so you need to log in as 'houdini'. So lets try this as 'houdini' with `houdini' OR 1=1; -- `. You get the same `Welcome admin! The "hash" for account 'houdini' is 'Not a hash'.`. So this is still matching the same user as before based on the 'Welcome admin!'. The issue is the `OR 1=1` part is just making and, mostlikely, returning the first match and 'admin' is early in the alphabet. Lets just try to sort with `houdini' OR 1=1 ORDER BY username DESC LIMIT 1; -- `. And that works!

`Welcome Houdini, here's your flag: ACI{6a4352fb5adfa2bbccbe3a09965}`.

Note:
So I was super dumb and missed the obvious (but I noticed it doing this write-up)! Just do not do the `OR 1=1`. You can just log in with `houdini'; -- `. Problem solved.
