Lookup details
==============

This module inserts and maintains certain user details from [Lookup](http://www.lookup.cam.ac.uk/), the University of Cambridge directory, for users accessing Drupal through [Raven](http://www.raven.cam.ac.uk/).

Authors
-------

* Chris Wilkinson <chris.wilkinson@admin.cam.ac.uk>

Requirements
------------

* [Raven authentication module](https://github.com/misd-service-development/drupal-raven)
* [PHP LDAP library](http://php.net/manual/en/book.ldap.php)

Fields
------

All Lookup-maintained fields are shown on the user edit form, but are disabled as any changes would be overwritten.

### Name

The user's display name in Lookup is added to the username and password section on the profile page.

If the display name itself is suppressed in Lookup, the registered name is used. If that's suppressed, Lookup simply reverts to the CRSid.

It is available is a token (`[user:lookup-name]`) for use in modules such as [RealName](http://drupal.org/project/realname), and is also a filter in views.

### E-mail address

If the user's primary e-mail address in Lookup is available, the e-mail address in Drupal is replaced. If it is suppressed, the existing value is left unchanged.