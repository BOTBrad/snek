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
  /* stop gap solution to test growing */
  let s =
    if (line == "g") {
      Snek.grow 3 s
    } else {
      s
    };
  /* stop gap solution to test fruit regenration */
  let b =
    if (line == "f") {
      Board.new_fruit s b
    } else {
      b
    };
  let dir = switch (Snek.to_dir "w" "a" "d" "s" line) {
    | Some d => d
    | None => Snek.current_dir s
  };
  let new_s = Snek.turn dir s;
  if (Snek.crashed new_s || Board.crashed new_s b) {
    ()
  } else {
    main b new_s
  }
};

Random.self_init ();
let s = Snek.make 4 { pos: (5, 5), dir: Snek.Left };
let b = Board.make 20 20 s;
main b s;

