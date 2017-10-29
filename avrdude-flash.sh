#!/bin/bash

avrdude -p atmega32u4 -c avr109 -U flash:w:%1 -P %2
