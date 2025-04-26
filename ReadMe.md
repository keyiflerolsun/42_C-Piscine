# 💻 C'de RAM, Pointer ve Array Mantığı

Bu doküman, RAM’in nasıl çalıştığını, pointer'ların ne işe yaradığını ve array'lerin bellekte nasıl yerleştiğini **temelden** başlayarak açıklar. Anlatım boyunca sade ama sağlam bir çizgide ilerlenir. Amaç sadece kodu değil, altında yatan **hafıza modelini** anlamaktır.

---

## 1️⃣ Neden RAM?

C dilinde tüm veriler RAM'e yazılır. Çünkü:

- CPU yalnızca RAM'deki adreslere doğrudan erişebilir.
- Diskteki verilerle işlem yapılamaz; önce RAM'e alınmaları gerekir.
- Her veri, RAM'de bir **adres** ile temsil edilir.

Bu yüzden C'de her değişkenin bir adresi (yeri) ve değeri (içeriği) vardır.

---

## 2️⃣ Bir Değişken RAM’de Nasıl Görünür?

```c
int ecole = 42;
```

RAM'deki karşılığı:

```
RAM:
+------------+
|     42     | ← ecole
+------------+
  0x1000 (örnek adres)
```

- `ecole` **değişkeni**, `42` **değerini** doğrudan taşıyan bir kutudur.
- CPU bu değere ulaşmak için RAM adresi olan `0x1000`'i kullanır.

---

## 3️⃣ Pointer: Bir Değişkenin Adresini Saklamak

```c
int ecole = 42;
int *ptr = &ecole;
```

```
RAM:
+------------+           +------------+
|  0x1000    | ← ptr     |     42     | ← ecole
+------------+           +------------+
  0x2000                   0x1000
```

| İfade     | Açıklama                                        | RAM'deki Karşılığı |
|-----------|--------------------------------------------------|---------------------|
| `ecole`   | RAM’deki değeri doğrudan taşır                   | `42`                |
| `&ecole`  | `ecole` değişkeninin adresini verir              | `0x1000`            |
| `ptr`     | `&ecole` yani `0x1000` adresini saklar           | `0x1000`            |
| `&ptr`    | `ptr` değişkeninin RAM'deki adresini verir       | `0x2000`            |
| `*ptr`    | `ptr`'nin gösterdiği adresteki değeri okur       | `42`                |

---

> `*ptr = 100;` ile RAM’deki değeri değiştirmek mümkündür.

```c
*ptr = 100;
```

```
RAM:
+------------+           +------------+
|  0x1000    | ← ptr     |    100     | ← ecole (güncellendi)
+------------+           +------------+
  0x2000                   0x1000
```

---

## 4️⃣ Array Bellekte Nasıl Yerleşir?

```c
int numbers[3] = {100, 200, 300};
```

```
RAM:
+------------+------------+------------+
|   100      |    200     |    300     |
+------------+------------+------------+
  0x3000       0x3004       0x3008
     ↑            ↑            ↑
&numbers[0]  &numbers[1]  &numbers[2]
```

- Her eleman RAM’de ardışık yerlerde saklanır.
- `int` tipi 4 byte yer kapladığı için adresler 4’er artar.

```c
numbers         == &numbers[0]   // Adres: 0x3000
*(numbers + 1)  == numbers[1]    // Değer: 200
*(numbers + 2)  == numbers[2]    // Değer: 300
```

---

### 🧠 Bunlar Aynı Şeyi Söylüyor Gibi… Ama Tam Değil!

| İfade             | Ne Yapar?                                    |
|-------------------|-----------------------------------------------|
| `numbers`         | Dizinin ilk elemanının adresini verir         |
| `&numbers[0]`     | Aynı adresi daha açık şekilde verir           |
| `numbers[1]`      | 2. elemanın değerini getirir (200)            |
| `*(numbers + 1)`  | Adrese 1 eleman ileri gidip değeri getirir    |

---

### 💡 Akılda Kalması İçin:

- `numbers` → dizinin başı (adres)
- `numbers[i]` → klasik okuma
- `*(numbers + i)` → aynı yere ulaşmanın "pointerlı" yolu

```c
// Bunlar aynıdır:
int x = numbers[2];
int y = *(numbers + 2);
```

> İki yol da RAM’de aynı yere gider: `0x3008 → 300`

---

## 5️⃣ Değer mi, Adres mi?

```c
char x = 'M';
char *p = &x;
```

- `x` → RAM’deki değeri doğrudan temsil eder. (`write(1, &x, 1)`)
- `&x` → x’in RAM’deki adresidir.
- `*p` → Adresi kullanarak o adresteki değeri okur.

---

### 💡 Peki fark ne?

```c
write(1, &x, 1);     // 'M'
write(1, p, 1);      // 'M'  → çünkü p = &x
```

Bu iki ifade aynı sonucu verir. Ama:

- `x` → değişkenin **kendisi**  
- `*p` → değişkenin **adresine gidip** değerini okur

---

### 🧠 Ne Zaman Önemli?

Bu fark basit örneklerde aynı sonucu verse de:

- Bellek üzerinde **dolaylı erişim**,
- Fonksiyonlara **adresle veri geçirme**,
- Dinamik yapıların yönetimi

gibi durumlarda çok önemlidir.

```c
*p = 'İ';  // RAM'deki değeri günceller
```

> Yani mesele sadece "değer okumak" değil, **nasıl ulaştığın** ve **ne kadar kontrol sahibi olduğun**.

---

## 6️⃣ C'de "String" Aslında Nedir?

C'de gerçek bir "string" tipi yoktur. Bunun yerine karakter dizileri (char array) vardır.

```c
char campus[] = "istanbul";  // stack'te, değiştirilebilir
char *campus = "istanbul";   // .rodata, sabit
```

### A. Değiştirilebilir string (stack)

```c
char campus[] = "istanbul";
```

```
RAM:
+-----+-----+-----+-----+-----+-----+-----+-----+------+
| 'i' | 's' | 't' | 'a' | 'n' | 'b' | 'u' | 'l' | '\0' |
+-----+-----+-----+-----+-----+-----+-----+-----+------+
 0x4000 ...                                    0x4008
```

- Her karakter RAM’de ayrı adreslerde tutulur.
- `\0` string’in sonunu belirtir.
- Bu yapı **değiştirilebilir**.

```c
campus[0] = 'I';  // ✔️ geçerli
```

### B. Sabit string (read-only / .rodata)

```c
char *campus = "istanbul";
```

Bellekte iki parça oluşur:

- `campus` → **stack**’te bir pointer’dır
- `"istanbul"` → **.rodata**’da sabit olarak tutulur

```
Stack:
+------------+
|  0x5000    | ← campus
+------------+
  0x6000

Sabit string'in yer aldığı alan (.rodata):

+-----+-----+-----+-----+-----+-----+-----+-----+------+
| 'i' | 's' | 't' | 'a' | 'n' | 'b' | 'u' | 'l' | '\0' |
+-----+-----+-----+-----+-----+-----+-----+-----+------+
  0x5000 ...                                    0x5008
```

- `campus` bir pointer’dır, sabit verinin adresini tutar.
- Bu yapıdaki string **değiştirilemez**.

```c
campus[0] = 'I';  // ❌ Tanımsız davranış, program çökebilir
```

> 📌 Detaylı bellek bölümleri için: `stack`, `heap`, `.rodata` konularını araştırın.

---

## 7️⃣ `argc` ve `argv` Nedir?

C programlarında `main` fonksiyonu genellikle şöyle tanımlanır:

```c
int main(int argc, char **argv)
```

| Parametre | Açılımı            | Anlamı                                 |
|-----------|--------------------|----------------------------------------|
| `argc`    | **arg count**       | Kaç tane argüman var? (sayı)           |
| `argv`    | **arg values**      | Argümanların kendisi (liste halinde)   |

---

### 🧪 Örnek: Terminalden çalıştırdık

```bash
./a.out 42 istanbul
```

Bu durumda:

```c
argc == 3

argv[0] → "./a.out"
argv[1] → "42"
argv[2] → "istanbul"
```

---

### 🧱 Bellekte Nasıl Görünür?

```
argv (char **argv)
     ↓
+------------+------------+------------+
|  0x7000    |  0x7010    |  0x7020    | ← char * array (argv)
+------------+------------+------------+
     ↓            ↓             ↓
  argv[0]      argv[1]       argv[2]
     ↓            ↓             ↓
 "./a.out"      "42"        "istanbul"   ← char array’ler
```

Array'ler nasıl görünüyordu;

```
+------+------+------+------+------+------+
| '.'  | '/'  | 'a'  | ...  | 't'  | '\0' | ← argv[0]
+------+------+------+------+------+------+
0x7000  7001   7002    ...    7006   7007   → "./a.out"

+-----+-----+------+
| '4' | '2' | '\0' | ← argv[1]
+-----+-----+------+
0x7010  7011  7012   → "42"

+------+------+------+------+------+------+------+
| 'i'  | 's'  | 't'  | ...  | 'u'  | 'l'  | '\0' | ← argv[2]
+------+------+------+------+------+------+------+
0x7020  7021   7022    ...    7026   7027   7028   → "istanbul"
```

---

### 📌 Zincirleme Yapı Özet

```c
char **argv      →  Liste (dizi) gibi davranır
char *argv[i]    →  i. argümanın adresi (bir string)
char  argv[i][j] →  string'in j. karakteri
```

---

### 🔍 Örneklerle Açalım

```c
**argv     → '.'  // argv[0][0]
argv[1][0] → '4'  // "42" string'inin ilk karakteri
argv[2][3] → 'n'  // "istanbul" kelimesinde 4. karakter
```

Hepsi bellekte farklı seviyelerde dolaşır:

| İfade        | Ne Getirir?                        | Bellekte Nerede?        |
|--------------|------------------------------------|-------------------------|
| `argv`       | Argüman listesi                    | `char **`               |
| `argv[0]`    | İlk argümanın adresi               | `char *` (örn.: 0x7000) |
| `*argv`      | Aynı şey: `argv[0]`                | `char *`                |
| `**argv`     | İlk karakter: `'.'`                | `char`                  |
| `argv[2][3]` | `"istanbul"` içindeki `'a'`        | `char`                  |

---

### 🧠 `**argv` Neden Gerekli?

Çünkü:

- `argv` → bir dizi (`char *argv[]`) → yani **birden fazla string**
- O diziyi temsil etmek için → `char **argv`
- Her `argv[i]` → bir `char *`
- Her `char *` → bir `char[]` (string)

Yani:

```
char **argv → [char *] → ["42"] → ['4', '2', '\0']
```

Bu yüzden `**argv` dediğimizde:

```c
**argv == argv[0][0]
```

---

### 🧪 `write()` ile RAM'de gezelim

```c
write(1, argv[0], 8);      // "./a.out"
write(1, argv[1], 2);      // "42"
write(1, &argv[2][4], 1);  // 'n'
```

---

### 🧠 Hafif Kavrama Oyunu

| Soru                        | Cevap                     |
|-----------------------------|---------------------------|
| `argv[0][0]` nedir?         | `'.'`                     |
| `argv[1][1]` nedir?         | `'2'`                     |
| `argv[2][5]` nedir?         | `'b'`                     |
| `*argv` nedir?              | `argv[0]`                 |
| `**argv` nedir?             | `'./a.out'[0]` yani `'.'` |

---

🕊 Katıldığınız için teşekkürler, görüşmek üzere.. 👋