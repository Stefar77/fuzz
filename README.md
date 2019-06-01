# fuzz
Instruction fuzzing for testing OS stability

-- Do not run on your bare metal unless you are at the console and want to create a panic --

- Currently running this as non-privileged user in bhyves on a FreeBSD12-P3 host -
- I was able to crash CentOS, FreeBSD 12 RELEASE, FreeBSD 12-P4, FreeBSD 13 HEAD and FreeBSD13/ARM64 -


Just cc -o fuzz fuzz.c and sh fuzz.sh, wait a couple of seconds/minutes/hours/days depending on the OS.

Doesn't seem to work on Ubuntu (but it's still testing)

fuzz2.c is pseudo random and needs a seed as parameter (unsigned int)
fizz2.sh runs fuzz2 with different seeds and displays the seed until it crashes so if we hit a critical bug we can reproduce it.

Also did this only with a couple if pushes and then an int 0x80 call but that makes one big mess in your filesystem.


If you try fuzz2 on FreeBSD 12-P4 (1 or 2 cores, 8GB RAM) start somewhere high like 1000000, I'm still testing and just restarted after some changes in the code and vm

interesting seeds for fuzz2

265542 (FBSD12/P4, FBSD13/HEAD)

355881 (FBSD12/P4)
