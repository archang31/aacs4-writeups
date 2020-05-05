# The SQL Always Sucks

## Web Security -- 150 points

### Description

We discovered an application in our environment that is apparently under development. Please identify the risk it poses. http://{{server}}:{{port}}  
  
**Note:** Solutions to this problem are known to be sensitive to connection latency. If your solution is working but very slowly, you may be able to speed up the process by running it from the competition's [shell server](/shell).

### Hints

* It's sometimes useful to know what kind of database is behind a webapp before trying to attack it. It can save you time and really narrow your efforts. I wonder if the developers accidentally left any clues laying around.
* SQL injuection attacks don't always result in you getting raw database contents sent directly back to you. Sometimes it is all about [patience](https://www.sqlinjection.net/time-based/) and [timing](https://hackernoon.com/timing-based-blind-sql-attacks-bd276dc618dd).
* Some attacks just are not practical to do by hand because they require precision and *lots* of repetition. Thankfully, tools like [sqlmap](https://github.com/sqlmapproject/sqlmap/wiki/Usage) can automate much of this for you. It even comes pre-installed on our shell server!
* Many tools use unique user-agent strings by default. If you notice that curl or sqlmap don't appear to be working properly, you may need to look into whether you can configure them to "impersonate" something else.


### Write-up

No write-up or walk-through has been published for this challenge yet.

