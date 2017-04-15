/* snek segment */
type snegment =
  (int, int);

type snek = {
  head :int,
  segs :array snegment,
};

let make (len :int) (head :snegment) :snek => {
  head: 0,
  segs: Array.make len head,
};

