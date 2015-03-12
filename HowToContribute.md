## Use Git ##

Patches should be submitted against the latest head in the master branch:
```
git clone https://code.google.com/p/msn-pecan/
```

You can commit your changes locally, but before that you need to configure your user:
```
git config --global user.name John Doe
git config --global user.email john.doe@gmail.com
```

To commit all the changes:
```
git commit -a
```

## Use the mailing-list ##

Patches should be sent to the mailing list: [msn-pecan@googlegroups.com](mailto:msn-pecan@googlegroups.com). Ideally you should be subscribed, but that's not required.

In order to send proper emails, configure `git send-email`:
```
git config sendemail.to msn-pecan@googlegroups.com
```

Generate and send patches (with a cover letter):
```
git send-email --cover-letter--annotate master
```

For more `git send-email` tricks check [this post](http://felipec.wordpress.com/2009/10/25/git-send-email-tricks/).