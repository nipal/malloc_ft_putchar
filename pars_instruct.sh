objdump -d $1 | tr "
" "#" | cut -d "#" -f 6- | tr "#" "
" | sed "s/^ *[0-9a-f]*:.//g" | sed "s/\(	.*\)*	.*//g" | tr "
" " " | sed "s/  */ /g"
