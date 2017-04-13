let module Board = Board;

let b : Board.board = {
  width: 20,
  height: 20,
};

let rec main () => {
  let line = read_line ();
  if (line != "exit") {
    print_int b.width;
    print_char '\n';
    print_string line;
    print_char '\n';
    main ()
  }
};

main ();

