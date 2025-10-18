package Rozwiazanie is

type Pojazd is record
  Rejestracja : Integer := 56789;
  Ulica       : Integer := -1;
  Prawoskret  : Boolean := False;
end record;

task type Rondo(MAX : Positive) is
    entry Wpusc(samochod : in Pojazd);
    entry Opusc(samochod : in Pojazd);
    
    entry ExtraEntryA(samochod : in Pojazd);
    entry ExtraEntryB(samochod : in Pojazd);
    entry ExtraEntryC(samochod : in Pojazd);
    entry ExtraEntryD(samochod : in Pojazd);
end Rondo;

end Rozwiazanie;