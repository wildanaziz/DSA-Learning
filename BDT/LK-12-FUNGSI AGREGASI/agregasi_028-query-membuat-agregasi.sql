SELECT ESSN as 'Kode Pegawai', PNo as 'Nomor Proyek', SUM(Jam) as 'Total Jam'
FROM Bekerja
GROUP BY ESSN, PNo, Jam;

SELECT DNama AS 'Nama Departemen', MGRSSN AS 'Kode Manager', COUNT(MGRSSN)AS 'Jumlah Manager'
FROM Departemen
GROUP BY DNama, MGRSSN;

SELECT ESSN as 'Kode Pegawai', Nama_anggota AS 'Nama Anggota Keluarga', Hubungan, COUNT(Hubungan) as 'Jumlah Anggota'
FROM Keluarga
GROUP BY ESSN, Nama_anggota, Hubungan;

SELECT e.Nama as 'Nama Pegawai', k.Nama_anggota as 'Nama Anggota Keluarga', COUNT(k.Nama_anggota) as 'Jumlah Anggota'
FROM Employee e
JOIN Keluarga k ON e.SSN = k.ESSN
GROUP BY e.Nama, k.Nama_anggota;

SELECT d.DNama AS 'Nama Departemen', e.Nama AS 'Nama Manager', COUNT(d.DNumber) AS 'Jumlah Departemen yang Dikelola'
FROM departemen d
JOIN employee e ON d.MGRSSN = e.SSN
GROUP BY d.Dnama, e.Nama;


