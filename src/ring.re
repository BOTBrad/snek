type ring 'a = {
  head: int,
  buf: array 'a,
};

let make (len: int) (v: 'a) :ring 'a => {
  head: 0,
  buf: Array.make len v,
};

