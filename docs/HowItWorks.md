# Funzionamento alla base di Enigma

Questa versione non comprende i **modificatori**.

## Struttura

La struttura parte dalla **tastiera**, passa dai **rotori**, attraversa il **riflettore**, torna indietro attraverso i **rotori** e va in **output**.

### Tastiera

La tastiera è nel layout tedesco, quindi prevede il seguente ordine:

```
Q U E R T Z U I O A S D F G H J K P Y X C V B N M L
```

L'input dalla tastiera passa dai **modificatori** (non emulati) e va in ingresso al primo rotore.

### Rotore

Il rotore è una struttura circolare che ha nella parte destra (input) le 26 lettere dell'alfabeto disposte nel layout della tastiera e nella parte sinistra altre 26 lettere disposte in modo differente in base al rotore utilizzato. 

Per facilità considereremo ogni rotore come una tabella a 26 righe e due colonne, che rappresenteranno da una parte le 26 lettere possibili in input, e dall'altra le 26 lettere corrispondenti ad ogni posizione.

Esistono 3 rotori, ognuno con una disposizione delle lettere nella parte sinistra differente. Da questo momento i nomi dei rotori saranno:

* **ROS** - Rotore posizionato a sinistra
* **ROC** - Rotore posizionato al centro
* **ROD** - Rotore posizionato a destra

Prendendo in considerazione una posizione specifica nel rotore, identificata come posizione 0, ogni lettera avrà una propria posizione rispetto ad essa (da 0 a +25).

Se la lettera in output da **ROD** sarà in posizione **n**, allora la lettera in input a **ROC** sarà esattamente quella in posizione **n**.

La funzione del singolo rotore quindi sarà proprio quello di modificare la posizione della lettera in entrata con un'altra posizione. Se infatti la lettera in input è per esempio la **A** nella colonna di destra, in output avremo la lettera **A** ma nella nuova posizione relativa alla colonna di sinistra.

Quindi:

* l'**input** di un rotore è deciso dalla posizione della lettera in **output** dal rotore adiacente a destra
* l'**output** di un rotore è la lettera ricevuta in **input** ma in una nuova posizione

Fondamentale è infine il **movimento dei rotori**. Per ogni lettera premuta sulla tastiera, **ROD** compirà un giro. Ogni 26 giri di **ROD**, **ROC** compirà un giro. Ogni 26 giri di **ROC**, **ROS** compirà un giro. In questo modo ad ogni lettera inserita corrisponderà sempre una traduzione differente.

### Riflettore

Il riflettore ha un funzionamento molto simile a quello dei rotori. Il suo funzionamento è il seguente:
1) Prende in **input** nella colonna di sinistra la posizione dell'**output** di **ROS**
2) La fa corrispondere alla lettera adiacente nella colonna di destra, che chiameremo **x**
3) La posizione di output del riflettore sarà quella di **x** ma nella colonna di destra

L'output del riflettore andrà in input a **ROS**, quindi la traduzione riattraverserà i rotori ma in ordine opposto; l'input avverrà nella colonna di sinistra e l'output da quella di destra.

## Impostare la chiave

Affinché mittente e destinatario possano rispettivamente cifrare e decifrare il messaggio devono utilizzare la stessa chiave.

In Enigma questo è deciso da:

* L'ordine dei tre rotori (per esempio Rotore I sarà ROS, Rotore II sarà ROC, ecc...)
* Quale posizione di ogni rotore è identificata come 0 (quindi la lettera corrispondente a tale posizione)

Una volta impostati qqiesti valori, Enigma sarà pronto a funzionare.