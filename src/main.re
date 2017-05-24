let view (g :Game.state) :unit => {
  let s = g.snek;
  let b = g.board;
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

let rec main (g :Game.state) :unit => {
  view g;
  let line = read_line ();
  let d = switch (Snek.to_dir "w" "a" "d" "s" line) {
    | Some d => d
    | None => Snek.current_dir g.snek
  };
  switch (Game.step d g) {
    | None => ();
    | Some new_g => main new_g;
  }
};

Random.self_init ();
let g = Game.make ();

main g;

