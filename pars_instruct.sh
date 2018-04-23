#/bin/sh

objdump -d $1 | sed -E "s/^ *[0-9a-f]*:\t//g" | sed -E "s/ *\t.*$/ /g" | tr  '\n' "," | cut -d ',' -f 8- | sed "s/,//g"
