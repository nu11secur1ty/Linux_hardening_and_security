#!/usr/bin/bash
# Author V.Varbanovski @nu11secur1ty
protect_priv=Defaults
  sed -i 's/$protect_priv/#$protect_priv/' /etc/sudoers
protect_all=ALL 
  sed -i 's/$protect_all/#$protect_all/' /etc/sudoers
    sed -i 's/root/#root/' /etc/sudoers
exit 0;
