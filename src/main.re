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
    let view = Board.view b;
    print_string wall;
    Array.iter (fun a => {
      print_char '#';
      Array.iter print_char a;
      print_string "#\n"
    }) view;
    print_string wall;
    main ()
  }
};

main ();
