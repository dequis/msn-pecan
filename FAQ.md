## Why msn-pecan? ##

The short answer is: there are many problems with the Pidgin development team. It's basically impossible to implement anything there.

MSN is basically ignored by the core development team. That's why many features simply don't work properly, and never will.

msn-pecan is an escape route. The initial goal of providing a better Pidgin plug-in has been achieved, now it's time to create a standalone library, and expand to other applications, like Empathy.

## How do I use it? ##

See [HowToInstall](HowToInstall.md).

## How do I change my personal message ##

There's no concept of personal message in Pidgin, instead, you must use the status messages.

You can try to select a new status at the bottom of the main window, but instead of selecting another status, choose Available again. A field should appear below, where you can enter your new status message.

If you would like this behavior to improve, please vote on [issue 51](https://code.google.com/p/msn-pecan/issues/detail?id=51).

## What is an alias? ##

An alias is a "private name"; something you set for your contacts. A nickname is a "public name", and it's different from an alias; it's something your contact sets for himself.

If the displayed name changes constantly it means your contact has changed his nickname. If the display name doesn't change it means you have set an alias; aliases take precedence over nicknames.

You can see both the nickname and the alias in the tool-tip in Pidgin.

## My buddy's nickname is not updated ##

You might have an old alias. Try changing it by right-clicking your buddy and then select Alias, remove all the text so it's empty.

The text displayed should now be the nickname.

## Groups.im nicknames are not updated ##

Groups.im uses a feature called P4Context, in order for that feature to be exercised you need to make sure that your contacts don't have an alias set; otherwise Pidgin will override the dynamic nickname with the local alias.

## The emoticons are different ##

This is an open issue that needs to be fixed in libpurple, see [issue 5](https://code.google.com/p/msn-pecan/issues/detail?id=5).

For now you can try Andrei Neculau's original smileys [here](http://andreineculau.com/blog/2008/04/original-smileys/).

## My privacy settings are not saved properly ##

Unfortunately libpurple's privacy settings need a lot of work, and they don't map with what the WLM protocol offers. Block/Allow only the users below work, the rest of the options don't.

## I have an issue that is not mentioned here ##

Fill a report on the [issue list](http://code.google.com/p/msn-pecan/issues/list), following ReportingIssues.