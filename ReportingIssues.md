Open a ticket in the [issue tracker](http://code.google.com/p/msn-pecan/issues/list).

In general you want to provide at least the version of msn-pecan you are using, and preferably a way to reproduce the problem. Most of the time, however you'll have to provide a _debug log_.

You can use the same guidelines as [Pidgin uses](http://developer.pidgin.im/wiki/TipsForBugReports).

## Windows ##

Go to **Help->Debug Window**, try to reproduce the bug and then Save the result. Attach it to the bug report.

If you are getting a crash instead use a debug version of msn-pecan.

## Linux ##

If you are a Linux user just do this:

```
pidgin --debug > debug-log.txt
```

And attach the result to the bug.

### Crash ###

If you are getting a crash you need to provide the backtrace, which can be obtained by running piding on gdb. Remember to install the debug package as well (-dbg on debian, -debug on rpm).

However, it's **immensely** more helpful to provide a valgrind log:
```
valgrind --leak-check=full --log-file=valgrdind.txt pidgin
```

Everything will be really slow, but the output will be worth it :)