--Karol Dziekan



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



package body Rozwiazanie is

    task body Rondo is
        POLNOC   : constant Integer := 0;
        ZACHOD   : constant Integer := 1;
        POLUDNIE : constant Integer := 2;

        MAX : Positive := 100;

        function Czy_Prawoskret_Zachod_Poludnie(S : Pojazd) return Boolean is
        begin
           if S.Ulica = POLNOC then
              return False;
           else
              return S.Prawoskret;
           end if;
        end Czy_Prawoskret_Zachod_Poludnie;

    begin
        loop
            select
                accept Wpusc(samochod : in Pojazd) do
                    -- obsługa wjazdu
                end Wpusc;
            or
                accept Opusc(samochod : in Pojazd) do
                    -- obsługa wyjazdu
                end Opusc;
            or
                accept ExtraEntryA(samochod : in Pojazd) do

                end ExtraEntryA;
            or
                accept ExtraEntryB(samochod : in Pojazd) do

                end ExtraEntryB;
            or
                accept ExtraEntryC(samochod : in Pojazd) do

                end ExtraEntryC;
            or
                accept ExtraEntryD(samochod : in Pojazd) do

                end ExtraEntryD;
            or
                Terminate;
            end select;
        end loop;
    end Rondo;

end Rozwiazanie;