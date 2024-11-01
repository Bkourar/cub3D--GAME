i=0
for file in *.png; do
    mv -- "$file" "rld_$i.png"
    i=$((i + 1))
done