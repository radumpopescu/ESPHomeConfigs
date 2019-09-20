# ESPHomeConfigs
  
In order to run the commands easier add this to your `~/.bash_profile`
```bash
alias eh='docker run --rm -v "${PWD}":/config -it esphome/esphome'
```

## Commands 

##### Compile & deploy:
```bash
eh eLiving.yaml run
```
##### Logs
```bash
eh eLiving.yaml logs
```