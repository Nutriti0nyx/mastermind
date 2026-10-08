# PRINTF
***

## Task
Le principe est la reproduction du jeu du mastermind, répondant aux règles suivantes : 
L'utilisateur doit trouver un code secret à quatre chiffres entre un et 8 fourni, sinon généré aléatoirement.
L'utilisateur doit proposer une combinaison, est alors renvoyé le nombre de chiffres bien placés ainsi que des chiffres corrects mais mal placés.
Si la bonne combinaison est rentrée, le jeu s'arrête. Cela se produit également si l'utilisateur excède un nombre d'essais fourni, sinon défini à 10
En cas d'essai invalide, aucune comparaison n'est effectué et l'essai est redemandé
Entrer ctrl+D met fin au programme

## Description
Le code est généré avec la fonction generation(), utilisant rand()%9, générant un chiffre entre 0 et 8. Les entiers sont transformés en caractères et la chaine est utilisée comme code. Celui-ci est remplacé si un est rentré manuellement
Une boucle est créée et ne s'arrête que lorsque le code est trouvé ou lorsque le nombre d'essai est épuisé.
Le code rentré dans le terminal est lu avec read() et celui-ci commence à être comparé lorsque le caractère \n est détecté. L'essai, après vérification, est parcouru. Les index sont comparés et un compteur est mis à jour en conséquences.
Si les chiffres ne sont pas les mêmes, le chiffre de l'essai est recherché avec la fonction into(), ici créée pour chercher un caractère dans une chaine et renvoyer true s'il apparait au moins un certain nombre de fois, fourni en argument.
Un tableau de 9 chiffres est gardé afin de compter l'apparition de chaque chiffre dans chaque essai. Il est réinitialisé après chaque essai avec la fonction resetArray.
Si aucune valeur n'est lue, c'est que ctrl+D a été rentré. Read() ne renvoie alors rien, et le programme est arrêté.

## Installation
Un Makefile lie chaque fonction créée avec le programme principal et l'exécute pour lancer le jeu.
Les en-têtes stdio.h, stdlib.h, string.h, stdbool.h et unistd.h sont utilisées
Le programme se lance avec la commande :
  make

Le Makefile lance avec 10 essais et un code invalide (ce qui génère un code aléatoire à la place). Il est nécessaire de le modifier pour changer les paramètres.

## Usage
Lancé, le programme s'arrête jusqu'à que l'utilisateur rentre un essai dans le terminal. L'essai renvoie alors en fonction :
- Que le code est incorrect
- Le nombre de chiffres bien placés et de chiffres corrects mais mal placés
- Que le jeu est gagné lorsque tous les chiffres sont bien placés
- Que le jeu est perdu lorsque le nombre de tentatives tombe à zéro.
Les trois premiers cas redemandent alors un essai à rentrer dans le terminal.

Entrer ctrl+D lorsque le terminal demande un code met fin au programme.
