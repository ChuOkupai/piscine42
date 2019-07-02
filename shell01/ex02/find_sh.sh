#!/bin/sh
find . -type f -name '*.sh' | sed 's/.*\///' | sed 's/...$//'