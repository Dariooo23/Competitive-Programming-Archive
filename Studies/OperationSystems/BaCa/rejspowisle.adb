-- Karol Dziekan

package body Rozwiazanie is

   type Phase_Type is (Sales, Boarding, Leaving);

   task body Przystan is
      Tickets_Sold     : Natural := 0;
      Total_Amount     : Integer := 0;
      On_Board         : Natural := 0;
      Current_Cruise   : Natural := 0;
      Employee_Trigger : Boolean := False;
      Phase            : Phase_Type := Sales;
   begin
      loop
         select
            when Phase = Sales and then Tickets_Sold < MAX =>
               accept Kasa (cena  : in  Integer;
                            bilet : out Integer) do
                  bilet := Current_Cruise;
                  if cena = 0 then
                     Employee_Trigger := True;
                  else
                     Tickets_Sold := Tickets_Sold + 1;
                     Total_Amount := Total_Amount + cena;
                  end if;
               end Kasa;

               if Employee_Trigger
                 or else Tickets_Sold = MAX
                 or else Total_Amount >= WYSTARCZY
               then
                  Phase := Boarding;
                  if Tickets_Sold = 0 then 
                     Current_Cruise   := Current_Cruise + 1;
                     Employee_Trigger := False;
                     Phase            := Sales;
                  end if;
               end if;

         or
            when Phase = Boarding and then On_Board < Tickets_Sold =>
               accept Wejdz;
               On_Board := On_Board + 1;
               if On_Board = Tickets_Sold then
                  Phase := Leaving;
               end if;

         or
            when Phase = Leaving and then On_Board > 0 =>
               accept Zejdz;
               On_Board := On_Board - 1;
               if On_Board = 0 then
                  Current_Cruise   := Current_Cruise + 1;
                  Tickets_Sold     := 0;
                  Total_Amount     := 0;
                  Employee_Trigger := False;
                  Phase            := Sales;
               end if;

         or
            when Phase = Sales =>
               delay 1.0;
               if Tickets_Sold = 0 then
                  exit;               
               else
                  Phase := Boarding; 
               end if;
         end select;
      end loop;
   end Przystan;

end Rozwiazanie;