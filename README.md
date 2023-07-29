# Kutuphane-Sistemi
kayıt ol, giris yap , öğrenci ve çalışan yetkisi bu yetkilerin de farklı erişim haklarının olduğu, dosya kaydetmenin de kullanıldığı bir kütüphane sistemi

Proje Açıklaması:

Bu proje, bir kütüphane yönetim sistemi oluşturmayı amaçlayan C programını içermektedir. Program, kullanıcıların kütüphane sisteminde kayıt olmalarını, giriş yapmalarını ve kütüphane işlemlerini gerçekleştirmelerini sağlar. Program, kullanıcıları iki tür yetkiye ayırır: öğrenci ve çalışan.

Projenin Ana Özellikleri:

- Kayıt Ol: Kullanıcılar, ad, soyad, yetki seviyesi (öğrenci veya çalışan) ve şifre bilgilerini girerek kütüphane sistemine kayıt olabilirler. Kayıt işlemi sırasında rastgele bir kullanıcı ID numarası oluşturulur ve bu ID numarası daha önce kullanılmamışsa kayıt işlemi tamamlanır.

- Giriş Yap: Kayıtlı kullanıcılar kütüphane sistemine giriş yapabilirler. Bu işlem için kullanıcı ID ve şifre bilgileri istenir. Eğer ID ve şifre doğru ise kullanıcıya yetkisi doğrultusunda giriş izni verilir.

- Kitapları Görüntüle: Öğrenciler, kütüphanede bulunan kitapları görüntüleyebilirler. Kitapların adı, yazarı, yayınevi, sayfa sayısı ve mevcut durumu gibi bilgiler ekrana yazdırılır.

- Kitap Arama: Öğrenciler, kütüphanede bulunan kitapları adlarına göre arayabilirler. Eğer kitap mevcut ise kitap bilgileri ekrana yazdırılır, aksi halde "kitap mevcut değil" mesajı verilir.

- Kitap Ekleme: Çalışanlar, yeni kitapları kütüphaneye ekleyebilirler. Kitap adı, yazarı, yayınevi ve sayfa sayısı bilgileri alınır ve yeni kitap sisteme eklenir.

- Üyeleri Görüntüleme: Çalışanlar, kütüphaneye kayıtlı olan üyelerin listesini görüntüleyebilirler. Üye adı, soyadı, ID numarası ve yetki seviyesi bilgileri ekrana yazdırılır.

- Çıkış: Kullanıcılar sistemden çıkış yapabilirler. Çıkış yaparken yapılan değişiklikler dosyaya kaydedilir.

Not: Proje, kullanıcı bilgilerini ve kitap bilgilerini dosyalara kaydederek veri saklamaktadır. Kullanıcılar ve kitaplar için ayrı ayrı dosyalar kullanılmıştır.

Bu kütüphane yönetim sistemi, kullanıcı dostu bir arayüzle kullanıcıların kütüphane işlemlerini kolaylıkla gerçekleştirmelerine olanak tanır. Programın çalışma mantığı, kullanıcıların yetki seviyesine göre farklı işlemler yapabilmesine dayanmaktadır. Proje, kütüphane yönetim sistemi ihtiyaçlarını karşılamak üzere tasarlanmıştır ve daha geniş kütüphane sistemlerinin temel altyapısını oluşturabilecek niteliktedir.
