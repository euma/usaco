open(my $in,  "<",  "namenumdict.txt")  or die "Can't open input.txt: $!";
while (<$in>) {
  print length($_);
  print " $_";
}
close $in or die "$in: $!";
