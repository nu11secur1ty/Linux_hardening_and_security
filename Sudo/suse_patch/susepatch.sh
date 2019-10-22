#!/usr/bin/bash
# Author V.Varbanovski @nu11secur1ty

  sed -i 's/Defaults/#Defaults/' /etc/sudoers
  sed -i 's/ALL/#ALL/' /etc/sudoers
  sed -i 's/root/#root/' /etc/sudoers
exit 0;
