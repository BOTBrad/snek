let b :Board.board = {
  width: 20,
  height: 20,
};

let wall = String.make (b.width + 2) '#' ^ "\n";

let view (b :Board.board) (s :Snek.snek) :unit => {
  print_string wall;
  for y in 0 to (b.height - 1) {
    print_char '#';
    for x in 0 to (b.width - 1) {
      if (Snek.at x y s) {
        print_char '#'
      } else {
        print_char ' '
      };
    };
    print_string "#\n";
  };
  print_string wall
};

let rec main (s :Snek.snek) :unit => {
  view b s;
  let line = read_line ();
  let dir = switch (Snek.to_dir "w" "a" "d" "s" line) {
    | Some d => d
    | None => Snek.current_dir s
  };
  switch (Snek.turn dir b s) {
    | Ok new_s => main new_s
    | Crash _ => ()
  }
};

main (Snek.make 4 { pos: (5, 5), dir: Snek.Left });

