# ws-priva
private work space A for development on "libpriva.a", privileged developers only

## building

`$ make -C lib/priva/build/arm-debug install` builds `libpriva.a`, runs it's
tests and installs is to blib/priva

`$ git subrepo push blib/priva` then pushes the installed binaries and
headers to its shared repo.

Note: The Makefile is a quick-hack to have something executable. Will be
replaced by the real project-files or build-scripts.
