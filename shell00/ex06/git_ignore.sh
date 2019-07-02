#!/bin/sh
git status -s --ignored | grep '!!' | sed 's/!! //'
