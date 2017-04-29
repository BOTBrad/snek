let view (b :Board.board) (s :Snek.snek) :unit => {
  let wall = String.make (b.width + 2) '#' ^ "\n";
  print_string wall;
  for y in 0 to (b.height - 1) {
    print_char '#';
    for x in 0 to (b.width - 1) {
      if (Snek.at x y s) {
        print_char '#'
      } else if ((x, y) == b.fruit) {
        print_char 'O'
      } else {
        print_char ' '
      };
    };
    print_string "#\n";
  };
  print_string wall
};

let rec main (b :Board.board) (s :Snek.snek) :unit => {
  view b s;
  let line = read_line ();
  let dir = switch (Snek.to_dir "w" "a" "d" "s" line) {
    | Some d => d
    | None => Snek.current_dir s
  };
  let s = Snek.turn dir s;
  if (Snek.crashed s || Board.crashed s b) {
    if (Board.won s b) {
      print_endline "you win!"
    } else {
      print_endline "you lost :(\nplay again? (y/n)";
      let again = read_line ();
      if (again.[0] == 'y') {
        run_game ()
      } else {
        ()
      }
    }
  } else {
    let (b, s) =
      if (Board.hit_fruit s b) {
        (Board.new_fruit s b, Snek.grow 5 s)
      } else {
        (b, s)
      };
    main b s
  }
}

and run_game () => {
  let s = Snek.make 4 { pos: (5, 5), dir: Snek.Left };
  let b = Board.make 20 20 s;
  main b s
};

Random.self_init ();
run_game ();

