(* Ce fichier a été généré par ç, ne pas l'éditer *)

(**
 * Un petit programme écrit en OCaml (https://OCaml.org), rédigé avec des mots-clés en anglais,
 * Il définit une fonction factorielle rec and exécute un test of test.
 *
 * Voir <https://github.com/Naereen/ocaml-mots-cles-en-francais/>
 *
 * Copyright Lilian Besson, 2021, publié sous la licence MIT
 * Voir <https://lbesson.mit-license.org/>
*)


(* Include the English one, to compare with it *)
let rec fact (n : int) =
  match n with
  | n when n < 0 -> failwith "Error: n has to be >= 0 for fact."
  | 0 -> 1
  | 1 | 2 -> if n=1 then 1 else 2
  | n -> n * (fact (n-1))
;;

let recursif fact2 (n : int) =
  match n with
  | n when n < 0 ->
    echoueavec "Erreur: n doit être >= 0 for fact2."
  | 0 -> 1
  | 1 | 2 -> if n=1 then 1 else 2
  | n -> n * (fact2 (n-1))
;;

let afficher = Format.printf;;

afficher "Test avec fact2 écrite avec les mots clés en français !\n%!";;
assert (1 = (fact2 1));;
assert (2 = (fact2 2));;
assert (6 = (fact2 3));;
for n = 6 to 10 faire
  afficher "fact2(%i) = %i\n%!" n (fact2 n);
done;;
for n = 13 downto 11 faire
  begin
    afficher "fact2(%i) = %i\n%!" n (fact2 n);
    assert ((fact2 n) = (fact n));
  end
done;;

let n = ref 3 in
while !n < 6 faire
  afficher "fact2(%i) = %i\n%!" !n (fact2 !n);
  incr n;
done;;
