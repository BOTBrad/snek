let b :Board.board = {
  width: 20,
  height: 20,
};

let s :Snek.snek =
  Snek.make 4 (5, 5);

let rec main () => {
  let line = read_line ();
  if (line != "exit") {
    let wall = String.make (b.width + 2) '#' ^ "\n";
    print_string wall;
    for y in 0 to b.height {
      print_char '#';
      for x in 0 to b.width {
        if (Snek.at x y s) {
          print_char '#'
        } else {
          print_char ' '
        };
      };
      print_string "#\n";
    };
    print_string wall;
    main ()
  }
};

main ();

