First disable all your msn-pecan accounts.

Then, on the console, run this:
```
HAZE_PERSIST=1 HAZE_DEBUG=all /usr/lib/telepathy/telepathy-pecan > "/home/user/MyDocs/msn-pecan.log"
```

Finally, enable only one of your accounts.

Once you reproduce the problem, [create a new ticket](http://code.google.com/p/msn-pecan/issues/entry) with the log file attached. Remember to remove sensible information.