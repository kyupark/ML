for f in *.png; do
  convert ./"$f" -compress none ./"${f%.png}.pgm"
done
