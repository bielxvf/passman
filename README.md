# passman
The man that manages your passwords.

# Dependencies
```
sudo pacman -S libsodium gcc clang
```
If you want the copy command `-c` to work, install `xclip` too

# Install
```
git clone https://codeberg.org/billy02357/passman
cd passman
sudo make install
```

# TODO
* [x] List passwords
* [x] Create password
* [x] Print password
* [x] Remove password
* [x] Copy password (xclip)
* [x] Rename a password
* [x] Print error on wrong master password
* [x] Backup all passwords
* [ ] --new option takes optional argument with the new password
* [ ] Restore from .tar backup

# Contributing
- Use `clang-format` on all files (`make` runs it)
- Use large and descripting variable names
- Better to write nice and easy to read code than comment too much
- Add your name to modified files (if you care)
- Have fun
