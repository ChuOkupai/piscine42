#!/bin/sh
ifconfig -a | grep ether | cut -c 8-24