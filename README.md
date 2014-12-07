ssh-agent-confirm
=================

Confirm uses of your SSH key by SSH commandline.

SETUP
=====

Get the peer offset for your kernel (see find_gdb_offset directory); run the .sh script and copy the last line.

Put this into netstat_unix (struct_unix_sock__peer_offset).

Install netstat_unix into a root-owned directory and add it to your sudoers, like so:

bucko   ALL=(ALL) NOPASSWD: /usr/local/bin/netstat_unix

This tool is used to find the peer (the 'ssh' process) which is asking for authentication, as SSH does not tell us.

This could be neater, if Linux would just tell us. Credit to the idea of debugging the kernel (and much of the code) to:

https://github.com/lemonsqueeze/unix_sockets_peers

Now stick the ssh_agent_confirm script into your ~/bin or wherever, and ensure you start ssh-agent with the $SSH_ASKPASS
environment variable set to the location of that script. You'll need $DISPLAY set, too -- it'll try to fire up GUI utils,
and in any case ssh-agent won't invoke $SSH_ASKPASS if $DISPLAY is not set.

Make sure you ssh-add with the '-c' commandline parameter, or the script won't be invoked.

You'll need zenity (it's used to display dialogs from bash).


FILES
=====

You'll get a directory ~/.ssh_agent_confirm with a log and an auto_allow file.


BEHAVIOUR
=========

Tries to identify the peer SSH process. Checks the key fingerprint and commandline against its own whitelist. If it's not
there, gives a prompt. You can give a regex to catch commandlines, for example, I have "^ssh git@github.com " as one such
regex, which allows all github operations on one particular key without prompting.

There is no way to make a deny whitelist right now. Add it if you like; I pretty much always allow my keys, I just don't
like the idea that they are authed in secret.
