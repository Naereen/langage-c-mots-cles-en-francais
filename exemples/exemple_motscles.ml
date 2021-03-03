(* Ce fichier a été généré par ç, ne pas l'éditer *)

(**
 * Un petit programme écrit en OCaml (https://OCaml.org), rédigé avec des mots-clés en anglais,
 * Il fait beaucoup of choses of base que permet OCaml and exécute des tests dessus.
 *
 * Voir <https://github.com/Naereen/ocaml-mots-cles-en-francais/>
 *
 * Copyright Lilian Besson, 2021, publié sous la licence MIT
 * Voir <https://lbesson.mit-license.org/>
*)

(* Ces changements sont faciles with faire avec un Stdlib_french.ml, if on voulait, ou un ~/.ocamlinit *)
let echoueavec = failwith;;
let ( non ) = ( not );;

let afficher = Format.printf;;

afficher "Testons presque tous les autres mots-clés Français...\n%!";;

let x:int =
  try
    begin
      2021/0
    end
  with _ -> 42;;
assert (x = 42);;

let y = 40
and   z = 2
in begin
  let answertolife = y + z in
  assert (answertolife = 42)
end;;

assert true;;
assert (non (false));;
assert (true || false);;
assert (true && (non (false)));;

open List;;
assert ((length [1;2;3]) = 3);;

afficher "Fait for les tests en Français !\n%!";;
