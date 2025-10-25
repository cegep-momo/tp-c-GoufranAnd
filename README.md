# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de les copiers dans le repertoire `build` avec l'application `bibliotheque`

# Veille technologique
# Question 1: C++
Dans ce projet, j'ai pris le temps de bien comprendre la notion et l'utilisation du pointeur intelligent: std::unique_ptr. Ce type de pointeur possède et gère un objet dynamique de manière exlusive, il est donc le seul responsable de la mémoire de cet objet. Lorsque ce pointeur sort de sa portée ou lorsqu'on lui assigne un autre pointeur via operator= ou reset(), il détruit automatiquement l'objet qu'il gère à l'aide d'un delete. Cette gestion automatique rend alors le code plus sur et propre, en évitant les fuites de mémoire. std::unique_ptr ne peut pas etre copié, mais peut etre déplacé, ce qui permet de transférer la propriété d'un objet sans dupliquer la mémoire. Il est aussi compatible avec les conteneurs de la STL, comme std::vector, ce qui est très utile dans ce projet. Cette compatibilite s'explique par le fait qu'un pointeur intelligent peut etre déplacé sans etre copié, permettant alors au vecteur de réorganiser des éléments sans problème.