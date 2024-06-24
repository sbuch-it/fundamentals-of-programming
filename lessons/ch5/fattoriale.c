/*
  cap04_fattoriale.c: Factorial computation
  Copyright (C) 2006 Giovanni Organtini (G.Organtini@roma1.infn.it)

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

  This program has been extracted from "Programmazione Scientifica",
  Pearson Education ed. (2006), by Barone, Marinari, Organtini and
  Ricci-Tersenghi. ISBN 8871922425.
*/

/*aggiungere controllo su n*/
/*cosa succede se il numero non e' rappresentabile? aggiungere un controllo p*i-p*/
#include <stdio.h>
#include<math.h>


main() {
  int n, i;
  unsigned long long int p = 1;
    
    

  printf("Inserisci un numero intero non negativo: ");
  scanf("%d", &n); //aggiungere controllo sull'input
  for (i = 1; i <= n; i++) {
	p *= i;
  }
 printf("%d!=%llu\n", n, p);

}
