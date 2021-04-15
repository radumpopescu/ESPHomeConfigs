docker run --rm -v "${PWD}":/config -it esphome/esphome 

docker run --rm -v "${PWD}":/config -it esphome/esphome air.yaml run --no-logs
docker run --rm -v "${PWD}":/config -it esphome/esphome eEntrance.yaml run --no-logs
docker run --rm -v "${PWD}":/config -it esphome/esphome eHeatDown.yaml run --no-logs
docker run --rm -v "${PWD}":/config -it esphome/esphome eHeatUp.yaml run --no-logs
docker run --rm -v "${PWD}":/config -it esphome/esphome eKitchen.yaml run --no-logs
docker run --rm -v "${PWD}":/config -it esphome/esphome eLiving.yaml run --no-logs
docker run --rm -v "${PWD}":/config -it esphome/esphome eOffice.yaml run --no-logs
docker run --rm -v "${PWD}":/config -it esphome/esphome waterBig.yaml run --no-logs
docker run --rm -v "${PWD}":/config -it esphome/esphome waterSmall.yaml run --no-logs
docker run --rm -v "${PWD}":/config -it esphome/esphome rolls.yaml run --no-logs