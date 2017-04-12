let rec main () => {
  let line = read_line ();
  if (line != "exit") {
    print_string line;
    print_char '\n';
    main ()
  }
};

main ();

