# PCO: Labo5, Tobogan

J.Châtillon, J.Smith

### Implémentation

Pour gérer l'accès concurrent à l'escalier, nous avons créé une classe *ToboganManager*. Cette classe hérite de *QTread*. Dans son constructeur, elle crée les *Kids* ainsi qu'un tableau de sémaphores (un sémaphore par marche). La méthode *.start()* sert à *run* les *Kids*. Nous avons décidé de faire cette classe pour faire en sorte que ce tableau ne soit pas en statique dans la classe *Kid* ou directement dans le *main*.

Nous avons modifié la classe *Kid* afin qu'elle contienne un pointeur sur le tableau de sémaphores pour qu'ils sachent s'ils ont accès aux escaliers. Avant de monter un escaler, ils doivent demander si il est libre (*.acquire()*) le monter, et le libéré quand ils sont en haut (*.release()*). Tous les *Kids* libèrent l'escaler précédent quand il sont en haut d'un escalier. Il a fallu aussi faire attention à libérer le dernier escalier quand l'enfant arrive en bas du toboggan.

### Bugs

Les *kids* n'apparaissent pas sur l'OS Windows malgré les instructions de modifications données par mail. Cependant, ça fonctionne très bien sur Linux.