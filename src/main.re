let b :Board.board = {
  width: 20,
  height: 20,
};

let wall = String.make (b.width + 2) '#' ^ "\n";

let rec main (s :Snek.snek) => {
  let line = read_line ();
  if (line != "exit") {
    let dir = switch (Snek.to_dir "w" "a" "d" "s" line) {
      | Some d => d
      | None => Snek.current_dir s
    };
    let new_s = Snek.turn dir s;
    print_string wall;
    for y in 0 to b.height {
      print_char '#';
      for x in 0 to b.width {
        if (Snek.at x y new_s) {
          print_char '#'
        } else {
          print_char ' '
        };
      };
      print_string "#\n";
    };
    print_string wall;
    main new_s
  }
};

main (Snek.make 4 { pos: (5, 5), dir: Snek.Left });

